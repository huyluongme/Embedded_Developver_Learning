#include <condition_variable>
#include <mutex>

class Semaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    unsigned int count;

public:
    Semaphore(unsigned int initial_count) : count(initial_count) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return count > 0; });
        --count;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }
};
#include <iostream>
#include <thread>
#include <vector>

class ATM {
private:
    double balance;
    std::mutex mtx;
    Semaphore sem;

public:
    ATM(double initial_balance, unsigned int max_users) 
        : balance(initial_balance), sem(max_users) {}

    void check_balance() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Current balance: $" << balance << std::endl;
    }

    void withdraw(double amount) {
        sem.acquire(); // Giới hạn số người sử dụng ATM đồng thời
        std::lock_guard<std::mutex> lock(mtx);
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal of $" << amount << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ", remaining balance: $" << balance << std::endl;
        }
        sem.release(); // Giải phóng vị trí
    }

    void deposit(double amount) {
        sem.acquire(); // Giới hạn số người sử dụng ATM đồng thời
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposited $" << amount << ", new balance: $" << balance << std::endl;
        sem.release(); // Giải phóng vị trí
    }
};

void user_transactions(ATM& atm, double withdraw_amount, double deposit_amount) {
    atm.deposit(deposit_amount);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    atm.withdraw(withdraw_amount);
}

int main() {
    ATM atm(1000.0, 2); // Giới hạn 2 người sử dụng ATM đồng thời

    // Ví dụ đồng bộ
    std::cout << "Synchronous example:" << std::endl;
    atm.check_balance(); // Kiểm tra số dư trước
    atm.deposit(200.0);
    atm.withdraw(150.0);
    atm.check_balance(); // Kiểm tra số dư sau

    // Ví dụ bất đồng bộ
    std::cout << "Asynchronous example:" << std::endl;

    std::vector<std::thread> threads;

    for (int i = 0; i < 50; ++i) {
        threads.emplace_back(user_transactions, std::ref(atm), 50.0, 100.0);
    }

    for (auto& t : threads) {
        t.join();
    }

    atm.check_balance(); // Kiểm tra số dư sau khi tất cả các thread đã thực hiện xong

    return 0;
}
