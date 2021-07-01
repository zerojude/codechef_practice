           #include<bits/stdc++.h>
           using namespace std ; 
           #define ar array 
           #define int long long  
           #define ld long double
           #define nl cout<<"\n" 

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
              if(x&1) a = (a*x)%mod;

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

  int t[4*MAX] ;
  int lazy[4*MAX]    ;

  void update( int x , int ss , int se , int qs , int qe )
  {
     int l = 2*x+1 ;  // left child
     int r = 2*x+2 ;  // right child
     
     int L = se-ss+1; // length of segment 
     
     if( lazy[x] != 0 )
     {
        t[x] = L - t[x];
        lazy[x] = 0 ;

        if( ss != se )
        {
           lazy[l] = 1 - lazy[l] ;
           lazy[r] = 1 - lazy[r] ;
        }
     }

     if( se < qs || qe < ss )return ;

     if( qs <= ss && se <= qe )
     {
         t[x] = L - t[x];
         if( ss != se )
         {
            lazy[l] = 1 - lazy[l] ;
            lazy[r] = 1 - lazy[r] ;
         }
         return ;
     }

     int mid = (ss+se)>>1; 

     update( l , ss , mid , qs , qe );
     update( r , mid+1, se , qs , qe );

     t[x] = t[l] + t[r] ;
  }

  int sum( int x , int ss , int se , int qs , int qe )
  {
     int l = 2*x+1;  // left child 
     int r = 2*x+2;  // right child 

     int L = se-ss+1;

     if( lazy[x] != 0 )
     {
        t[x] = L - t[x];
        lazy[x] = 0 ;

        if( ss != se )
        {
           lazy[l] = 1 - lazy[l] ;
           lazy[r] = 1 - lazy[r] ;
        }
     }


     if( qe < ss || se < qs )
      return 0 ;

     if( qs <= ss && se <= qe )
      return t[x] ;


     int mid = (ss+se)>>1;

     int left = sum( l , ss , mid , qs , qe );
     int right = sum( r , mid+1 , se , qs , qe );

     return left + right ; 
  }
 

//
//   update( root , seg_start , seg_end , query_start , query_end );
//   sum( root , seg_start , seg_end , query_start , query_end );
//


            
            void go(  )
            {
               memset( t , 0 , sizeof t );
               memset( lazy , 0 , sizeof lazy );

               int N , Q ; cin>>N>>Q;
               
                while(Q--)
                {
                   int a, b , c ;
                   cin>>a>>b>>c;

                   if( a == 0 )
                     update(0,0,N-1,b,c);
                   else
                   {
                     cout<<sum(0,0,N-1,b,c);
                     nl;
                   }
                }
            }

            main()
           {

              std::ios::sync_with_stdio(false);
              // cin.tie(0);
              // cout.tie(0);
              
              // freopen("input.txt", "r", stdin); 
              // freopen("output.txt", "w", stdout);
              
               int test = 1 ; while(test--)
               {
                  go();
               }
             
             
           } 
           

