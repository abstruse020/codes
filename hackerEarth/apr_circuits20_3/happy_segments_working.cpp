

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int mxn = 5e5+10;
     
    int block;
    int  a[mxn], happy[mxn], ans[mxn];
    int n, m, q;
    int freq[mxn];
    int flag;
    struct Query{
        int l, r, index;
    };
    Query queries[mxn];
    bool compare(Query x, Query y){
        if(x.l/block != y.l/block) return x.l/block < y.l/block;
        return x.r < y.r;
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=1; i<=m; i++) cin >> happy[i];
        cin >> q;
        block = sqrt(n);
        int l, r;
        for(int i=0; i<q; i++){
            cin >> l >> r, l--, r--;
            queries[i] = {l, r, i};
        }
     
        
        sort(queries,queries+q, compare);
        int L=0, R=-1, index;
        for(int i=0; i<q; i++){
            l=queries[i].l; r = queries[i].r;
            index = queries[i].index;
            flag=1;
             while(R<r){
                R++;
                freq[a[R]]++;
            }
               while(L<l){
                freq[a[L]]--;
                L++;
            }
              while(R>r){
                freq[a[R]]--;
                R--;
            }
             while(L>l){
                L--;
                freq[a[L]]++;
            }
            for(int j=l; j<=r; j++)
            {
                if(freq[a[j]] != happy[a[j]])
                {
                    flag=0;
                    break;
                }
            }
            if(flag == 0)
            ans[index]=0;
            else
            ans[index]=1;
     
            
     
        }    
        for(int i=0; i<q; i++){
            cout << ans[i] << '\n';
        }
    }

Language: C++14
