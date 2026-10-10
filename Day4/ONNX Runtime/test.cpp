// ==================================================================
//  用 C++ + ONNX Runtime 跑 YOLO 推理
//
//  模型：best.onnx（Cityscapes 5 类）
//  类别：0-car  1-person  2-truck  3-bus  4-traffic light
//
//  ★★ 标记的是「必须掌握」，其余是固定写法
// ==================================================================

#include <iostream>
#include <vector>
#include <onnxruntime_cxx_api.h>
using namespace std;

// 模型的 5 个类别名（顺序必须和训练时一致）
const char* CLASS_NAMES[] = { "car", "person", "truck", "bus", "traffic light" };
const int   CLASS_NUM     = 5;

// ==================================================================
//  工具函数：打印模型的输入输出信息
//
//  换新模型时调用一下，就能看到输入/输出叫什么名字、什么形状。
//  参数用引用 &session，避免复制整个 Session 对象。
// ==================================================================
void printModelInfo(Ort::Session& session) {
    Ort::AllocatorWithDefaultOptions allocator;   // 取名字要用（固定写法）

    cout << "===== 模型信息 =====" << endl;

    // ---- 输入 ----
    size_t in_count = session.GetInputCount();
    cout << "输入个数：" << in_count << endl;
    for (size_t i = 0; i < in_count; i++) {
        auto name  = session.GetInputNameAllocated(i, allocator);
        auto shape = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
        cout << "  输入[" << i+1 << "] 名字：" << name.get() << "   形状：[ ";
        for (auto d : shape) cout << d << " ";
        cout << "]" << endl;
    }

    // ---- 输出 ----
    size_t out_count = session.GetOutputCount();
    cout << "输出个数：" << out_count << endl;
    for (size_t i = 0; i < out_count; i++) {
        auto name  = session.GetOutputNameAllocated(i, allocator);
        auto shape = session.GetOutputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
        cout << "  输出[" << i+1 << "] 名字：" << name.get() << "   形状：[ ";
        for (auto d : shape) cout << d << " ";
        cout << "]" << endl;
    }

    cout << endl;
}

int main() {
    try {

        // ==============================
        //  1. 加载模型
        // ==============================
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "YoloOnnx");   // 环境
        Ort::SessionOptions session_options;                   // 选项（默认）
        Ort::Session session(env,                              // 会话：加载模型
            ORT_TSTR("D:/yolo-practice/output/cityscape_train_v3/weights/best.onnx"),
            session_options);
        cout << "模型加载成功！\n" << endl;

        printModelInfo(session);

        // ==============================
        //  2. 打印模型信息（换模型时看这里）
        // ==============================
        printModelInfo(session);

        // ==============================
        //  3. 准备输入数据
        // ==============================
        // 一张 1x3x960x960 的假图（全 0 = 纯黑），以后换成真图片
        vector<float>   input_data(1 * 3 * 960 * 960, 0.0f);
        vector<int64_t> input_shape = { 1, 3, 960, 960 };

        auto memory_info = Ort::MemoryInfo::CreateCpu(
            OrtArenaAllocator, OrtMemTypeDefault);             // 内存信息（固定写法）

        // ★★ 必须掌握 ①：把数据包成 Tensor
        //    5 个参数：内存信息 / 数据指针 / 数据个数 / 形状数组 / 形状维度数
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
            memory_info,
            input_data.data(),
            input_data.size(),
            input_shape.data(),
            input_shape.size());

        // ==============================
        //  4. 跑推理
        // ==============================
        const char* input_names[]  = { "images"  };
        const char* output_names[] = { "output0" };

        cout << "开始推理..." << endl;

        // ★★ 必须掌握 ②：执行推理（部署模型的核心一行）
        auto outputs = session.Run(
            Ort::RunOptions{ nullptr },
            input_names, &input_tensor, 1,      // 输入：名字、Tensor、个数
            output_names, 1);                   // 输出：名字、个数

        cout << "推理完成！\n" << endl;

        // ==============================
        //  5. 取出结果
        // ==============================
        // ★★ 必须掌握 ③：拿到结果数据的指针
        const float* out_data = outputs[0].GetTensorData<float>();

        // 输出形状 [1, 9, 18900]：1张图 / 每框9个数 / 18900个候选框
        // 内存排列是 9 行 × 18900 列，所以第 i 个框的第 j 个值 = out_data[j * 18900 + i]
        auto shape   = outputs[0].GetTensorTypeAndShapeInfo().GetShape();
        int  num_box = (int)shape[2];

        cout << "输出形状：[ ";
        for (auto d : shape) cout << d << " ";
        cout << "]" << endl;
        cout << "候选框数量：" << num_box << "\n" << endl;

        // ---------- 看看第 0 个框的 9 个数 ----------
        int i = 0;   // 看第 0 个框

        cout << "===== 第 " << i+1 << " 个框 =====" << endl;
        cout << "位置："
             << "cx=" << out_data[0 * num_box + i] << "  "
             << "cy=" << out_data[1 * num_box + i] << "  "
             << "w="  << out_data[2 * num_box + i] << "  "
             << "h="  << out_data[3 * num_box + i] << endl;

        cout << "各类别分数：" << endl;
        for (int c = 0; c < CLASS_NUM; c++) {
            cout << "  " << CLASS_NAMES[c] << "\t: "
                 << out_data[(4 + c) * num_box + i] << endl;
        }

    } catch (const exception& e) {
        cout << "出错了：" << e.what() << endl;
        return 1;
    }

    return 0;
}
