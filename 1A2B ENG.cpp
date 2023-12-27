//姜貴豐-12/11
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>  
#include <vector>

using namespace std;

// 生成四個不重複的隨機字母
string generateSecretCode() {
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_shuffle(letters.begin(), letters.end());
    return letters.substr(0, 4);
}

// 計算A和B的數量
void evaluateGuess(const string& secretCode, const string& userGuess, int& A, int& B) {
    A = B = 0;
    for (int i = 0; i < 4; ++i) {
        if (userGuess[i] == secretCode[i]) {
            A++;
        } else if (secretCode.find(userGuess[i]) != string::npos) {
            B++;
        }
    }
}

int main() {
    // 初始化
    srand(static_cast<unsigned>(time(0)));
    string secretCode = generateSecretCode();
    int attempts = 0;

    cout << "歡迎來到英文字母版1A2B遊戲！" << endl;

    do {
        // 接收玩家輸入
        string userGuess;
        cout << "請猜測四個不重複的英文字母：";
        cin >> userGuess;

        // 檢查輸入合法性
        if (userGuess.length() != 4 || userGuess[0] == userGuess[1] || userGuess[0] == userGuess[2] || userGuess[0] == userGuess[3] ||
            userGuess[1] == userGuess[2] || userGuess[1] == userGuess[3] || userGuess[2] == userGuess[3]) {
            cout << "請輸入四個不重複的英文字母！" << endl;
            continue;
        }

        // 計算A和B的數量
        int A, B;
        evaluateGuess(secretCode, userGuess, A, B);

        // 顯示結果
        cout << "結果：" << A << "A" << B << "B" << endl;

        // 增加猜測次數
        attempts++;

        // 判斷是否猜中
        if (A == 4) {
            cout << "恭喜你猜中了！答案是：" << secretCode << endl;
            cout << "總共猜了 " << attempts << " 次。" << endl;
            break;
        }

    } while (true);

    return 0;
}

