#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin >> n >> m;
    
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> cards;
    for(int i=0;i<n;++i){
        int num;
        cin >> num;
        cards.push(num);
    }
    
    for(int i=0;i<m;++i)
    {
        unsigned long long c1 = cards.top(); cards.pop();
        unsigned long long c2 = cards.top(); cards.pop();
        unsigned long long sum = c1 + c2;
        cards.push(sum);
        cards.push(sum);
    }
    
    unsigned long long total = 0;
    
    while(cards.empty() == false){
        total += cards.top();
        cards.pop();
    }
    
    cout << total << '\n';
}