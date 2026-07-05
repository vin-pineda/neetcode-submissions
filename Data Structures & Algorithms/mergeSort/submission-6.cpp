class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if(pairs.empty()) return pairs;
        mergeSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void mergeSortHelper(vector<Pair>& pairs, int s, int e) {
        if (e - s + 1 <= 1) return;

        int mid = (s + e) / 2;

        mergeSortHelper(pairs, s, mid);
        mergeSortHelper(pairs, mid + 1, e);
        merge(pairs, s, mid, e);
    }

    void merge(vector<Pair>& pairs, int s, int mid, int e) {
        vector<Pair> L(pairs.begin() + s, pairs.begin() + mid + 1);
        vector<Pair> R(pairs.begin() + mid + 1, pairs.begin() + e + 1);

        int i = 0, j = 0, k = s;

        while (i < L.size() && j < R.size()) {
            if (L[i].key <= R[j].key) pairs[k++] = L[i++];
            else pairs[k++] = R[j++];
        }
        while (i < L.size()) pairs[k++] = L[i++];
        while (j < R.size()) pairs[k++] = R[j++];
    }
};
