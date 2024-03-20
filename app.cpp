#include <bits/stdc++.h>
using namespace std;

int n;
string pat, fn, pre, suf;

int main()
{
    cin >> n;
    cin >> pat;
    int pos = pat.find('*');
    pre = pat.substr(0, pos);
    suf = pat.substr(pos + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> fn;
        if (pre.size() + suf.size() > fn.size())
        {
            cout << "NE"
                 << "n";
        }
        else
        {
            if (pre == fn.substr(0, pre.size()) && suf == fn.substr(fn.size() - suf.size()))
            {
                cout << "DA "
                     << "\n";
            }
            else
            {
                cout << "NE "
                     << "\n";
            }
        }
    }
    return 0;
}