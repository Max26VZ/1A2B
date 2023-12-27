//���Q��-12/11
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>  
#include <vector>

using namespace std;

// �ͦ��|�Ӥ����ƪ��H���r��
string generateSecretCode() {
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_shuffle(letters.begin(), letters.end());
    return letters.substr(0, 4);
}

// �p��A�MB���ƶq
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
    // ��l��
    srand(static_cast<unsigned>(time(0)));
    string secretCode = generateSecretCode();
    int attempts = 0;

    cout << "�w��Ө�^��r����1A2B�C���I" << endl;

    do {
        // �������a��J
        string userGuess;
        cout << "�вq���|�Ӥ����ƪ��^��r���G";
        cin >> userGuess;

        // �ˬd��J�X�k��
        if (userGuess.length() != 4 || userGuess[0] == userGuess[1] || userGuess[0] == userGuess[2] || userGuess[0] == userGuess[3] ||
            userGuess[1] == userGuess[2] || userGuess[1] == userGuess[3] || userGuess[2] == userGuess[3]) {
            cout << "�п�J�|�Ӥ����ƪ��^��r���I" << endl;
            continue;
        }

        // �p��A�MB���ƶq
        int A, B;
        evaluateGuess(secretCode, userGuess, A, B);

        // ��ܵ��G
        cout << "���G�G" << A << "A" << B << "B" << endl;

        // �W�[�q������
        attempts++;

        // �P�_�O�_�q��
        if (A == 4) {
            cout << "���ߧA�q���F�I���׬O�G" << secretCode << endl;
            cout << "�`�@�q�F " << attempts << " ���C" << endl;
            break;
        }

    } while (true);

    return 0;
}

