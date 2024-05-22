
/*      1.using const int R=3;
        const int c=2;
        void print(int mat[R][C])  {.... Then traversing the whole matrix}
*/
/*      2. using double pointers
            void print(int **arr,int n,int m)  {.... Then traversing the whole matrix}
            int main ()
            {
                int **arr;
                arr=new *int[m];    // m is the number of rows
                for(int i=0;i<m;i++)
                {
                    arr[i]=new int [n];  // n is the number of columns
                    for(int j=0;i<n;j++)
                    {
                        arr[i][j]=i;
                    }
                }
                print(arr,m,n);
                return 0;
            }
*/

/*      3. Using array of pointers
            void print(int *arr[],int m,int n){.... THen traversing the whole array}
            int main ()
            {
                int m,n;
                cin>>m>>n;
                int *arr[m];
                for(int i=0;i<m;i++)
                {
                    arr[i]=new int [n];
                    for(int j=0;j<m;j++)
                    {
                        arr[i][j]=i;
                    }
                }
                print(arr,m,n);
                return 0;
            }
*/

/*      4. Using Array of vectors
        void print(vector<int> arr[],int m)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<arr[i].size();j++)
                {
                    cout<<arr[i][j]<<" ";
                }
            }
        }
        int main ()
        {
            int m,n;
            cin>>m>>n;
            vector<int> arr[m];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    arr[i].push_back(i);
                }
            }
            print(arr,m,n);
            return 0;
        }
*/

/*      5. Using vector of vectors
            void print(vector<vector<int>> v)
            {
                for(int i=0;i<v.size();i++)
                {
                    for(int j=0;j<v[i].size();j++)
                    {
                        cout<<v[i][j]<<" ";
                    }
                }
            }

            int main ()
            {
                int m,n;
                cin>>m>>n;
                vector<vector<int>> arr;
                for(int i=0;i<m;i++)
                {
                    vector<int> v;
                    for(int j=0;j<n;j++)
                    {
                        v.push_back(i);
                    }
                    arr.push_back(v);
                }
                print(arr);
            }

*/

// Also create jagged array--> where each row contains different number of columns or elements