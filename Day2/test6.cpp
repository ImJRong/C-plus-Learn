// 练习：类的封装 —— 银行账户
// 私有成员 balance_，通过公有成员函数存/取/查

#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance_;        // 余额，私有

public:
    // 构造函数：传入初始余额
    BankAccount(double balance) {
        balance_ = balance;
    }

    // 存钱
    void deposit(double m) {
        balance_ += m;
        cout << "存款 " << m << " 元成功！" << endl;
    }

    // 取钱：余额不足则拒绝
    void withdraw(double m) {
        if (m > balance_) {
            cout << "余额不足！！取款 " << m << " 失败！" << endl;
        } else {
            balance_ -= m;
            cout << "取款 " << m << " 元成功！" << endl;
        }
    }

    // 查余额
    double getBalance() {
        return balance_;
    }
};

int main() {
    BankAccount zjr(1000);

    zjr.deposit(500);
    cout << "当前余额 " << zjr.getBalance() << " 元!" << endl;   // 1500

    zjr.withdraw(2000);                                          // 余额不足
    zjr.withdraw(300);
    cout << "当前余额 " << zjr.getBalance() << " 元!" << endl;   // 1200

    return 0;
}
