#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to perform a query
// Returns the path as a vector. Returns empty vector if path does not exist.
vector<int> ask(long long k) {
    cout << "? " << k << endl;
    int len;
    cin >> len;
    
    // If len is -1, it means invalid query or error -> exit immediately
    if (len == -1) {
        exit(0);
    }
    
    if (len == 0) {
        return {};
    }
    
    vector<int> path(len);
    for (int i = 0; i < len; ++i) {
        cin >> path[i];
    }
    return path;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    long long current_idx = 1;
    vector<long long> count(n + 1, 0); // Stores total paths starting at v
    vector<pair<int, int>> edges;

    for (int u = 1; u <= n; ++u) {
        // Step 1: Confirm start of block for u
        // The path at current_idx should be [u]. 
        // We query it to consume it and verifying our position.
        vector<int> p = ask(current_idx);
        
        if (p.empty()) {
            break; // Should not happen given constraints
        }
        
        long long start_u = current_idx;
        current_idx++; // Move past the path [u]
        
        // Step 2: Identify neighbors
        while (true) {
            // Probe the next path
            vector<int> path = ask(current_idx);
            
            // Check if we have moved past the block of u
            if (path.empty() || path[0] != u) {
                // We are done with vertex u
                count[u] = current_idx - start_u;
                // Note: current_idx is now pointing to start of u+1 (or is empty)
                // The outer loop will re-query this index, which is a slight redundancy (1 query)
                // but ensures robust logic state.
                break;
            }
            
            // We found a neighbor v
            int v = path[1];
            edges.push_back({u, v});
            
            if (v < u) {
                // Backward edge: We already know the count of paths starting at v
                current_idx += count[v];
            } else {
                // Forward edge: We do not know count[v]. 
                // We use Binary Search to find the end of the block starting with u->v
                
                long long L = current_idx + 1;
                // Upper bound: Max distinct paths is 2^30. 
                // We can use a safe constant like 2*10^9.
                long long R = current_idx + (1LL << 30); 
                long long boundary = current_idx;
                
                // Limit R to avoid overflow if needed, though long long is sufficient.
                if (R > (1LL << 60)) R = (1LL << 60); // Just sanity check
                
                // We search for the largest index 'ans' such that path[ans] starts with u -> v
                while (L <= R) {
                    long long mid = L + (R - L) / 2;
                    vector<int> check_p = ask(mid);
                    
                    bool match = false;
                    // Check if path starts with u, v
                    if (check_p.size() >= 2 && check_p[0] == u && check_p[1] == v) {
                        match = true;
                    }
                    
                    if (match) {
                        boundary = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
                
                // Move current_idx to the start of the next neighbor block
                current_idx = boundary + 1;
            }
        }
    }

    // Output result
    cout << "! " << edges.size() << endl;
    for (auto& e : edges) {
        cout << e.first << " " << e.second << endl;
    }
}

int main() {
    // Interactive problems don't usually require fast I/O, 
    // but ensures synchronization isn't an issue.
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}