class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
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

    void merge(vector<Pair>& arr, int s, int mid, int e) {
        vector<Pair> L(arr.begin() + s, arr.begin() + mid + 1);
        vector<Pair> R(arr.begin() + mid + 1, arr.begin() + e + 1);

        int i = 0;
        int j = 0;
        int k = s;

        while (i < L.size() && j < R.size()) {
            if (L[i].key <= R[j].key) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < L.size()) {
            arr[k++] = L[i++];
        }

        while (j < R.size()) {
            arr[k++] = R[j++];
        }
    }
};
