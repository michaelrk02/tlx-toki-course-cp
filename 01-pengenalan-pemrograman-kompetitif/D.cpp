// D - Hapus Satu Saja!
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    bool bisa = false;
    for (int i = 0; i < s1.length(); i++)
    {
        string s3;
        for (int j = 0; j < s1.length(); j++)
        {
            if (i != j)
                s3.push_back(s1[j]);
        }

        if (!s3.compare(s2))
        {
            bisa = true;
            break;
        }
    }
    cout << (bisa ? "Tentu saja bisa!" : "Wah, tidak bisa :(") << endl;
    return 0;
}
