// Definition for a pair.
// class Pair {
//     int key;
//     String value;
//
//     public Pair(int key, String value) {
//         this.key = key;
//         this.value = value;
//     }
// }
class Solution {
    public List<Pair> quickSort(List<Pair> pairs) {
        quickSort(pairs, 0, pairs.size()-1);
        return pairs;
    }
    public void quickSort(List<Pair> arr, int s, int e) {
        if (e - s + 1 <= 1) return;
        int index = s;
        Pair pivot = arr.get(e);
        
        for (int i = s; i < e; i ++) {
            if (arr.get(i).key < pivot.key) {
                Pair temp = arr.get(index);
                arr.set(index, arr.get(i));
                arr.set(i, temp);
                index++;
            }
        }

        arr.set(e, arr.get(index));
        arr.set(index, pivot);

        quickSort(arr, s, index - 1);
        quickSort(arr, index + 1, e);
    }
}
