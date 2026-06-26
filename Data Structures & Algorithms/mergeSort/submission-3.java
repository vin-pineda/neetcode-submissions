// Definition for a pair.
// class Pair {
//     public int key;
//     public String value;
//
//     public Pair(int key, String value) {
//         this.key = key;
//         this.value = value;
//     }
// }
class Solution {
    public List<Pair> mergeSort(List<Pair> pairs) {
        divide(pairs, 0, pairs.size()-1);
        return pairs;
    }

    public List<Pair> divide (List<Pair> pairs, int s, int e) {
        if (e - s + 1 <= 1) return pairs;
        int m = (s + e) / 2;
        divide (pairs, s, m);
        divide (pairs, m+1, e);
        conquer (pairs, s, m, e);
        return pairs;
    }

    public void conquer(List<Pair> pairs, int s, int m, int e){
        List<Pair> L = new ArrayList<>(pairs.subList(s, m+1));
        List<Pair> R = new ArrayList<>(pairs.subList(m+1, e+1));

        int i=0, j=0, k=s;
        while (i < L.size() && j < R.size()) {
            if (L.get(i).key <= R.get(j).key) {
                pairs.set(k, L.get(i));
                i++;
            } else {
                pairs.set(k, R.get(j));
                j++;
            }
            k++;
        }
        while (i < L.size()) {
            pairs.set(k, L.get(i));
            i++;
            k++;
        }
        while (j < R.size()) {
            pairs.set(k, R.get(j));
            j++;
            k++;
        }
    }
}
