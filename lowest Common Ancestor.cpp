           #include<bits/stdc++.h>
           using namespace std ; 
           #define ar array 
           #define int long long  
           #define ld long double
           #define nl cout<<"\n" 
           
           ld e = 1e-9; // epsilon 
           int x4[] = { 0 , 0 , 1 , -1 };
           int y4[] = { 1 , -1 , 0 , 0 };

           int x8[] = { 1 , 1 , 1 , -1 ,-1 ,-1 ,-1 , 1};
           int y8[] = { 0 , 1 , 0 ,  1 , 0 ,-1 , 0 ,-1};

           bool MBok( int M , int N , int i , int j ) // Matrix bound ok 
           {
             if( i >= 0 && j >= 0 && i < M && j < N )return 1 ; 
             else return 0 ; 
           }
        
   /***********************_____TEMPLATE-STARTS_____****************************/


   /***************************_____MATHS_____*********************************/

           int mod = 1e9+7 ;


           vector<ar<int,2>>factorise( int N )
           {
                  vector<ar<int,2>>res;
                  for( int a = 2 ; a*a <= N ; a++ )
                  {
                     int cnt = 0 ;
                     while( N%a == 0 )
                     {
                        cnt++ ;
                        N /= a ;
                     }
                     if( cnt != 0 )res.push_back({a,cnt});
                  }
                  if( N != 1 )
                     res.push_back({N,1});
                  return res; 
           }
           

           int modpow( int N , int x )
           {
              if( N == 0 )return 0 ; 
              if( N == 1 )return 1 ;
              if( x == 0 )return 1 ;
              int a = modpow( N , x/2 );
              
              a = (a*a)%mod;
              if(x&1) a = (a*N)%mod;

              return a%mod;
           }

           int inv( int N )
           {
               return modpow( N , mod-2 );
           }

           int nCr( int N , int r )
           {
              int b = N-r;
              r = min( r , b );
              int res = 1 ;

               for( int i = 0 ; i < r ; i++ )
               res = (res*(N-i))/(i+1);

               return res; 
           }
            

   /********************______Fenwick Tree______******************************/

   // note- class is implemented considering the O-based indexing 
   // fenwick  Tree ____ update - ____ query // formate is followed 
   // FT_PR - > point update range query 
   // FT_RP - > range update point query
   // FT_RR - > range update range query

    // sum();
    // add();
    // at();

    class FT_PR { public : vector<int>T; int N ; FT_PR( int N ) { this->N = N ; T.assign(N+1,0); } FT_PR( vector<int>&A ):FT_PR(A.size()) { for( int i = 0 ; i < N ; i++ ) { add(i,A[i]); } } void add( int k , int val ) { k++ ; while( k <= N ) { T[k] += val; k += k&-k ; } } int sum( int k ) { int s = 0 ; k++; while( k >= 1 ) { s += T[k]; k -= k&-k; } return s ; } int sum(int l, int r) { return sum(r)-sum(l-1); } int at(int k) { return sum(k,k); } }; class FT_RP { public : int N ; vector<int>T ; FT_RP(int N) { this->N = N ; T.assign(N+1,0); } FT_RP(vector<int>&A):FT_RP(A.size()) { for( int i = 0 ; i < N ; i++ ) add(i,i,A[i]); } void add( int k , int val) { k++; while(k<=N) { T[k] += val; k += k&-k ; } } void add( int l , int r , int val ) { add(l,val); add(r+1,-val); } int at( int k ) { int s = 0 ; k++; while( k >= 1 ) { s += T[k] ; k -= k&-k ; } return s ; } }; class FT_RR { public : int N ; vector<int>T1 , T2 ; FT_RR(int N ) { this->N = N ; T1.assign(N+1,0); T2.assign(N+1,0); } FT_RR(vector<int>&A):FT_RR(A.size()) { for( int i = 0 ; i < N ; i++ ) { add( i , i , A[i] ); } } void add( int k , vector<int>&T , int val ) { k++; while( k <= N ) { T[k] += val; k += k&-k; } } void add( int l , int r , int val ) { add(l,T1,val); add(r+1,T1,-val); add(l,T2,val*(l-1)); add(r+1,T2,-val*r); } int sum( int k , vector<int>&T ) { k++; int s = 0 ; while( k >= 1 ) { s += T[k] ; k -= k&-k; } return s ; } int sum( int k ) { return sum(k,T1)*k - sum(k,T2); } int sum(int l , int r ) { return sum(r) - sum(l-1); } int at( int k ) { return sum(k,k); } };


                               // template-END //
   /*************************************************************************/

            
  const int MAX = 100005;
  
  void dfs( vector<int>g[] , int N , int d , int i , int p  , vector<int>& dis )
  {
      if( i >= N )return ;

      for( auto j : g[i] )
      {
          if( j != p )
          {
              dis[j] = 1 + d ;
              dfs( g , N , d+1 , j , i , dis ) ;
          }
      }

      return ;
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////


  void __init( vector<int>g[] , int N , vector<int>&dis )
  {

       dis[0] = 0 ;
       dfs( g , N , 0 , 0 , -1 , dis );

       return ;
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int timer = 0 ;

vector<vector<int>>t ;
vector<int>tin ;
vector<int>tout ;
vector<int>dis;










      

         void gen( vector<int>g[] , int i , int p , int N , int k )
         {
             t[i][0] = p ;


             tin[i] = ++timer ;

             for( int j = 1 ; j < k ; j++ )
               t[i][j] = t[t[i][j-1]][j-1];

             for( auto j : g[i] )
             {
                if( j != p )
                  gen( g , j , i , N , k );
             }

             tout[i] = ++timer ;
         }


          bool isE( int a , int b )
          {
              if( tin[a] <= tin[b] && tout[a] >= tout[b] )
               return 1 ; 
               return 0 ; 
          }

          int lca( int a , int b , int k )
          {

              if( isE( a , b ) )
               return a ;

              if( isE( b , a ) )
               return b ;


              for( int i = k-1 ; i >= 0 ; i-- )
              {
                 if( !isE( t[a][i] , b ) )
                 {
                   a = t[a][i] ;
                 }
              }
             
              return t[a][0] ; 

          }


         int len( int a , int b , int k )
         {
             int l = lca( a , b , k );
             return dis[a]+dis[b]-2*dis[l];
         }



         void go()
         { 
             int N ;  cin>>N ;
             vector<int>g[N];

             for( int i = 0 ; i < N-1 ; i++ )
             {
                int a,b; cin>>a>>b;
                g[a-1].push_back(b-1);
                g[b-1].push_back(a-1);
             }
            
             dis = vector<int>(N ,0 );
            
             __init( g , N , dis );

            
             timer = 0 ;
             
             int k = log2(N)+1;
            
             t = vector<vector<int>>(N,vector<int>(k,0));             
             tin = vector<int>(N,0);
             tout = tin ;

             gen( g , 0 , 0 , N , k );

             int Q ; cin>>Q ;

            
             while(Q--)
             {
                  int r , a , b ; 
                  cin>>r>>a>>b ;
                  r-- ; 
                  a-- ; b-- ;

                  
                  vector<ar<int,2>>A =
                  {
                     {r,0},
                     {a,0},
                     {b,0},
                     {lca(a,b,k),0},
                     {lca(a,r,k),0},
                     {lca(b,r,k),0}
                  }  ;


                  int mn = INT_MAX ;

                  for( auto &x : A )
                  {
                      int v = x[0];
                      int res = len( v , a , k) + len( v , r , k ) + len( v , b , k );
                      mn = min( mn , res );

                      x[1] = res ;
                      
                  }                

                 
                  for( auto x : A )
                  {
                      if( x[1] == mn )
                        {
                            cout<<x[0]+1<<endl;
                            break;
                        }

                  }
                  
                 



             }
            

             return ;             
             
         }
 

        int32_t main()
           {
              std::ios::sync_with_stdio(false);
              cin.tie(0);
              cout.tie(0);
              
              // freopen("input.txt", "r", stdin); 
              // freopen("output.txt", "w", stdout);
              
               int test = 1 ;
               // cin>>test;
               while(test--)
               {
                   go();                  
               }
               return 0 ;
           } 
             
           

