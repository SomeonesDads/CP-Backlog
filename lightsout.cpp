#include <bits/stdc++.h>
using namespace std;

// Standard Lights Out: pressing (r,c) toggles (r,c) and its 4 edge neighbors.
int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};

// idx mapping
inline int idx(int r,int c){ return r*8 + c; }

// Solve A x = b over GF(2). Board: 8x8 initial (0/1). Goal: all 1s.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> board(8, vector<int>(8));
    // read 8x8 ints (0/1)
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            if(!(cin >> board[r][c])) return 0;
            board[r][c] &= 1;
        }
    }

    const int N = 64;
    // matrix: N rows, N cols + 1 augment (at bit position N)
    vector< bitset<65> > mat(N);

    // build matrix
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            int i = idx(r,c);
            bitset<65> row;
            // for each press position (pr,pc), check if it toggles (r,c)
            for(int pr=0; pr<8; ++pr){
                for(int pc=0; pc<8; ++pc){
                    int j = idx(pr,pc);
                    bool toggles = false;
                    for(int d=0; d<5; ++d){
                        int nr = pr + dr[d], nc = pc + dc[d];
                        if(nr==r && nc==c){ toggles = true; break; }
                    }
                    if(toggles) row.set(j);
                }
            }
            // augmented column: we want final state = 1, so b_i = 1 XOR initial_i
            int bi = 1 ^ board[r][c];
            row.set(N, bi);
            mat[i] = row;
        }
    }

    // Gaussian elimination (mod 2)
    vector<int> where(N, -1);
    int row = 0;
    for(int col=0; col<N && row<N; ++col){
        int sel = -1;
        for(int i=row;i<N;i++) if(mat[i].test(col)){ sel = i; break; }
        if(sel == -1) continue;
        swap(mat[sel], mat[row]);
        where[col] = row;
        // eliminate other rows
        for(int i=0;i<N;i++){
            if(i!=row && mat[i].test(col)) mat[i] ^= mat[row];
        }
        row++;
    }

    // check consistency
    for(int i=0;i<N;i++){
        bool allzero = true;
        for(int j=0;j<N;j++) if(mat[i].test(j)){ allzero = false; break; }
        if(allzero && mat[i].test(N)){
            cout << "No solution exists (inconsistent system).\n";
            return 0;
        }
    }

    // construct a solution (free variables = 0)
    vector<int> ans(N, 0);
    for(int j=0;j<N;j++){
        if(where[j] != -1) ans[j] = mat[where[j]].test(N);
        else ans[j] = 0; // choose 0 for free var
    }

    cout << "Solution found. Press these positions (0-indexed r c):\n";
    for(int i=0;i<N;i++){
        if(ans[i]){
            cout << (i/8) << " " << (i%8) << "\n";
        }
    }
    return 0;
}
