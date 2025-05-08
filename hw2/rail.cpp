#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n = 0;
    while(cin >> n){
        while(true){
            if(n == 0) break;
            stack <int> stk;
            int count = 0;
            int a[1001];
            cin >> a[0];
            if(a[0] == 0) {
                cout << "\n";
                break;
            }
            for(int i = 1; i < n; i++){
                cin >> a[i];
            }
            for(int i = 1; i <= n; i++) {
                stk.push(i);
                while(true) {
                    if(!stk.empty() && stk.top() == a[count]){
                        count++;
                        stk.pop();
                    }
                    else break;
                }
            }
            if(stk.empty()) cout << "Yes\n";
            else cout << "No\n";
        }

    }
    return 0;
}