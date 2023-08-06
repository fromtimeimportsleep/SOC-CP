#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> degrees(n + 1);

    int x, y;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        degrees[x]++;
        degrees[y]++;
    }

    int c = 2;
    int starDegree = n - 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (degrees[i] == 2) {continue;}
        if (degrees[i] == 1) {c--;}
        else if (m == n - 1 && degrees[i] == starDegree) {cout << "star topology"; return 0;}
        else {cout << "unknown topology"; return 0;}
    }

    if (c == 0) {cout << "bus topology";} else {cout << "ring topology";}
}






