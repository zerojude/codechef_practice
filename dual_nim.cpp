           #include<bits/stdc++.h>
           using namespace std ; 
           #define ar array 
           // #define int long long  
           #define ld long double
           #define nl cout<<"\n" 
           
           ld e = 1e-9; // epsilon
           int mod = 1e9+7 ; // modular change if it is 

           int x4[] = { 0 , 0 , 1 , -1 };
           int y4[] = { 1 , -1 , 0 , 0 };

           int x8[] = { 1 , 1 , 1 , -1 ,-1 ,-1 ,-1 , 1};
           int y8[] = { 0 , 1 , 0 ,  1 , 0 ,-1 , 0 ,-1};

           bool MBok( int M , int N , int i , int j ) // Matrix bound ok 
           {
             if( i >= 0 && j >= 0 && i < M && j < N )return 1 ; 
             else return 0 ; 
           }
       

           


                                                                                                       


   // 888888ba                                                            dP              dP   oo                   
   // 88    `8b                                                           88              88                        
   // 88     88 .d8888b. .d8888b. dP    dP 88d8b.d8b. .d8888b. 88d888b. d8888P .d8888b. d8888P dP .d8888b. 88d888b. 
   // 88     88 88'  `88 88'  `"" 88    88 88'`88'`88 88ooood8 88'  `88   88   88'  `88   88   88 88'  `88 88'  `88 
   // 88    .8P 88.  .88 88.  ... 88.  .88 88  88  88 88.  ... 88    88   88   88.  .88   88   88 88.  .88 88    88 
   // 8888888P  `88888P' `88888P' `88888P' dP  dP  dP `88888P' dP    dP   dP   `88888P8   dP   dP `88888P' dP    dP 
                                                                                                              




// *************************_____MATHS_____******************************


     // ar<int,2> factorise( N )  // factorises the no return [ p , x ] == p^x format 
     // modpow( int N , x )       // N^x    
     // inv(x)                    // modulo inverse of a no 
     // nCr(N,r)                  // nCr combinatorics 
     // LCM(a,b)                  // lcm calculator 



// **************************_____LCA_____*******************************  


     // class is implented considering the input is 0 based indexing 
     
     // **-> if the input is in the 1 based indexing format then provide 1 in the parameter field like ---> t.read(1)

     // function implented are  

     // read()  // reads all ( N-1 ) edges of tree considering 0 based input
     // read(1) // reads all ( N-1 ) edges of tree considering 1 based input // it will manage // 
     //            after it you should provie 0 based input for all the query stuff

     // lca( a , b ) // lca query in O(logn) time 
     // len( a , b ) // path length between a to b 
     // depth( a )   // depth of node a 
     // display()    // prints all the useful information 




/********************______Fenwick Tree______******************************/

      // note- class is implemented considering the O-based indexing 
      // fenwick  Tree ____ update - ____ query // formate is followed 
      // FT_PR - > point update range query 
      // FT_RP - > range update point query
      // FT_RR - > range update range query
 
      // sum();
      // add();
      // at();






   // d888888b d88888b .88b  d88. d8888b. db       .d8b.  d888888b d88888b   
   //    88    88      88'YbdP`88 88   8D 88      d8' `8b    88    88         
   //    88    88ooooo 88  88  88 88oodD' 88      88ooo88    88    88ooooo    
   //    88    88      88  88  88 88      88      88   88    88    88        
   //    88    88      88  88  88 88      88      88   88    88    88.        
   //    YP    Y88888P YP  YP  YP 88      Y88888P YP   YP    YP    Y88888P   
                                                                                                             
                                                                                                          
 
vector<ar<int,2>>factorise( int N ) { vector<ar<int,2>>res; for( int a = 2 ; a*a <= N ; a++ ) { int cnt = 0 ; while( N%a == 0 ) { cnt++ ; N /= a ; } if( cnt != 0 )res.push_back({a,cnt}); } if( N != 1 ) res.push_back({N,1}); return res; } int modpow( int N , int x ) { if( N == 0 )return 0 ; if( N == 1 )return 1 ; if( x == 0 )return 1 ; int a = modpow( N , x/2 ); a = (a*a)%mod; if(x&1) a = (a*N)%mod; return a%mod; } int inv( int N ) { return modpow( N , mod-2 ); } int nCr( int N , int r ) { int b = N-r; r = min( r , b ); int res = 1 ; for( int i = 0 ; i < r ; i++ ) res = (res*(N-i))/(i+1); return res; } int LCM( int a , int b ) { return a*b/(__gcd(a,b)); }
class FT_PR { public : vector<int>T; int N ; FT_PR( int N ) { this->N = N ; T.assign(N+1,0); } FT_PR( vector<int>&A ):FT_PR(A.size()) { for( int i = 0 ; i < N ; i++ ) { add(i,A[i]); } } void add( int k , int val ) { k++ ; while( k <= N ) { T[k] += val; k += k&-k ; } } int sum( int k ) { int s = 0 ; k++; while( k >= 1 ) { s += T[k]; k -= k&-k; } return s ; } int sum(int l, int r) { return sum(r)-sum(l-1); } int at(int k) { return sum(k,k); } }; class FT_RP { public : int N ; vector<int>T ; FT_RP(int N) { this->N = N ; T.assign(N+1,0); } FT_RP(vector<int>&A):FT_RP(A.size()) { for( int i = 0 ; i < N ; i++ ) add(i,i,A[i]); } void add( int k , int val) { k++; while(k<=N) { T[k] += val; k += k&-k ; } } void add( int l , int r , int val ) { add(l,val); add(r+1,-val); } int at( int k ) { int s = 0 ; k++; while( k >= 1 ) { s += T[k] ; k -= k&-k ; } return s ; } }; class FT_RR { public : int N ; vector<int>T1 , T2 ; FT_RR(int N ) { this->N = N ; T1.assign(N+1,0); T2.assign(N+1,0); } FT_RR(vector<int>&A):FT_RR(A.size()) { for( int i = 0 ; i < N ; i++ ) { add( i , i , A[i] ); } } void add( int k , vector<int>&T , int val ) { k++; while( k <= N ) { T[k] += val; k += k&-k; } } void add( int l , int r , int val ) { add(l,T1,val); add(r+1,T1,-val); add(l,T2,val*(l-1)); add(r+1,T2,-val*r); } int sum( int k , vector<int>&T ) { k++; int s = 0 ; while( k >= 1 ) { s += T[k] ; k -= k&-k; } return s ; } int sum( int k ) { return sum(k,T1)*k - sum(k,T2); } int sum(int l , int r ) { return sum(r) - sum(l-1); } int at( int k ) { return sum(k,k); } };
#define nl cout<<"\n"  // neccesary to include
class LCA { public: int N = 0 , timer = 0 , k = 10; vector<vector<int>>g ; vector<vector<int>>t ; vector<int>tin; vector<int>tout; vector<int>dis ; LCA( int N ) { this->N = N ; k = log2(N)+1; timer = 0 ; vector<int>temp(N,0); tin = temp ; tout = temp ; dis = temp ; vector<vector<int>>temp1(N, vector<int>{} ); vector<vector<int>>temp2(N, vector<int>(k,0)); g = temp1; t = temp2; } void dfs( int i , int d , int p ) { for( auto j : g[i] ) { if( j != p ) { dis[j] = 1 + d ; dfs( j , d+1 , i ); } } } void lift( int i , int p ) { t[i][0] = p ; tin[i] = ++timer; for( int j = 1 ; j < k ; j++ ) t[i][j] = t[t[i][j-1]][j-1]; for( auto j : g[i] ) { if( j != p ) lift( j , i ); } tout[i] = ++timer; } void read( int z = 0 ) { for( int i = 0 ; i < N-1 ; i++ ) { int a , b ; cin>>a>>b; if( z == 1 ) { a--; b--; } g[a].push_back(b) ; g[b].push_back(a) ; } dis[0] = 0 ; dfs( 0 , 0 , 0 ) ; lift( 0 , 0 ); } bool isAncestor( int a , int b ) { if( tin[a] <= tin[b] && tout[a] >= tout[b] ) return 1 ; return 0 ; } int lca( int a , int b ) { if( isAncestor( a , b ) ) return a ; if( isAncestor( b , a ) ) return b ; for( int i = k-1 ; i >= 0 ; i-- ) { if( !isAncestor( t[a][i] , b ) ) { a = t[a][i] ; } } return t[a][0] ; } int len( int a , int b ) { int l = lca( a , b ); return dis[a] + dis[b] - 2*dis[l] ; } int depth( int a ) { return dis[a] ; } void display() { cout<<"****internal implementation is 0-bases indexing**********"; nl; cout<<"****please be carefull while reading input give 1- when input is in the 1 base indexing "; nl; nl; nl; cout<<"graph is in the formate a---> p , q , r "; nl; nl; for( int i = 0 ; i < N ; i++ ) { cout<<i+1<<"------->"; for( int j = 0 ; j < g[i].size() ; j++ ) cout<<g[i][j]+1<<" "; nl; } nl; nl; cout<<"lift array"; nl; for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < k ; j++ ) cout<<t[i][j]<<" \n"[j==k-1]; nl; nl; cout<<"distance array"; nl; for( auto x : dis ) cout<<x<<" "; nl; nl; } };











































       bool ok( int x , int b )
       {
            
             int st = 0 ;
             
             if( b )st = 1 ;


            if( x != 0 )
            {
                return st ;
            }

            else
            {
                 return !st ;
            }

       }




       void go()
       {

           int N ; cin>>N ;
           vector<int>A(N);

           for( auto &x : A )cin>>x ;

            int x = accumulate( A.begin() , A.end() , 0 , []( int a, int b ){return a^b;});


          if( x == 0 || N%2 == 0 )
            cout<< "First";
          else
            cout<<"Second";

          nl;

       }




        int32_t main()
           {
              std::ios::sync_with_stdio(false);
              cin.tie(0);
              cout.tie(0);
              
              // freopen("input.txt", "r", stdin); 
              // freopen("output.txt", "w", stdout);
              
               int test = 1 ;
               cin>>test;
               while(test--)
               {
                   go();                  
               }
               return 0 ;
           } 
             
           

