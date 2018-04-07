#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x <<": " << (x) << endl
#ifdef LOCAL
#define see(x) cout  << #x << ": " << (x) << endl
#endif

#define RED     "\033[31m"
#define RESET "\033[0m"
#define alert(x) cerr << RED << x << RESET << endl
#ifndef LOCAL
#define see(x)
#endif

template<class T>
int sign(const T &a) {
    if(a==0) return 0;
    if(a>0) return 1;
    return -1;
}

template<typename T>
void println(const T &t) {
    cout << t << '\n';
}

template<typename T, typename ...Args>
void println(const T &t, const Args &...rest) {
    cout << t << ' ';
    println(rest...);
}

template<typename T>
void print(const T &t) {
    cout << t << ' ';
}

template<typename T, typename ...Args>
void print(const T &t, const Args &...rest) {
    cout << t;
    print(rest...);
}

// this overload is chosen when there's only one argument
template <class T>
void scan(T &t){
    cin >> t;
}

template<class T, class ...Args>
void scan(T &a, Args &...rest){
    cin >> a;
    scan(rest...);
}
int cas;
const int mod = 1e9+7;
using vec = vector<int>;
using mat = vector<vec>;
using pii = pair<int,int>;
using pip = pair<int,pii>;
using ll = long long;

ll POW(ll x, ll n){
    ll res = 1;
    for(;n; n/=2, x*=x, x%=mod){
        if(n&1){
            res *= x;
            res %= mod;
        }
    }
    return res;
}



const int N = 1e3+5;
const int M = 1<<20;

// #include <ext/pb_ds/priority_queue.hpp>

// typedef __gnu_pbds :: priority_queue<pip, less<pip>, __gnu_pbds::thin_heap_tag > Heap;

// Heap h;

// Heap::point_iterator pos[N][N];

bool done[N][N];
int todo[N][N];


void solve(int R, int C){
    int x = 1;
    int y = 1;
    // alert(R);
    // alert(C);
    // cerr << "_________________________________________________________________" << endl;
    for(int i=x; i<x+R; i++)
        for(int j= y; j<y+C; j++)
            done[i][j] = false;


    for(int i = x+1; i<= x +R-2; i++) {
        for (int j = y + 1; j <= y + C - 2; j++) {
		    todo[i][j] = 9;
        }
    }

    auto update=[x, y, R, C](int r, int c){
        for(int i=-1; i<=1; i++)
            for (int j = -1; j <= 1; j++) {
                int ti = r+i, tj = c+j;
                if(ti>=x+1 && ti<=x+R-2 && tj>=y+1 && tj<=y+C-2) {
			        todo[ti][tj]--;
                }
            }
    };

    int tot = R*C;

    auto select = [x, y, R, C](){
        int ma = 0;
        for(int i = x+1; i<=x+R-2; i++)
            for(int j = y+1; j<=y+C-2; j++)
                ma = max(ma, todo[i][j]);
        for(int i = x+1; i<=x+R-2; i++)
            for(int j = y+1; j<=y+C-2; j++)
                if(todo[i][j] == ma) return pii{i,j};

	};

    int r, c;
    // string deli = "===================";
    for(int i=1; i<=1000; i++){
        // cerr << deli << endl;
        // debug(i);
        // cerr << deli << endl;

	    auto top = select();

	    if(todo[top.first][top.second]==0){
            // cerr << "###todo[top.first][top.second]==0###" << endl;
            return;
        }

        // debug(top.first);
        // debug(top.second);
        // debug("HEHEDA");
	    // debug(todo[top.first][top.second]);
        fflush(stdout);

        // debug(tot);
        assert(top.first > 1 && top.second >1);
        // cout << top.first << ' ' << top.second << endl;
        println(top.first, top.second);
        fflush(stdout);
        scan(r, c);
        
        // debug(r);
        // debug(c);
        // debug(int(done[r][c]));

        if(r == 0 && c == 0){
            // cerr << "###r==0 && c==0###" << endl;
            return;
        }

        if(!done[r][c]){
            done[r][c] = true;
            --tot;
            if(tot == 0){
                // cerr << "###tot == 0####" << endl;
                return;
            }
            update(r, c);
        }
    }
}


int main(){
//#ifdef LOCAL
//    freopen("in.txt", "r", stdin);
//#endif
//    puts("HELLO,World!");
    int T;
    scan(T);
    // debug(T);
    while(T--){
//        printf("Case #%d: ", ++cas);
        int n = 0;
        cin >> n;
        int R, C;
        C = R = sqrt(n);
        
        if(C*R < n) ++R, ++C;
        assert(C*R >= n);

        // debug(n);
        // debug(R);
        // debug(C);

        // println(R, C);
//        if(n == 20){
//            R = 4;
//            C = 5;
//        }
//        else if(n == 200){
//            R = 14;
//            C = 15;
//        }//
        solve(R, C);
    }
    return 0;
}
