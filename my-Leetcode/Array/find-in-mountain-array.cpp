// Problem link:- https://leetcode.com/problems/find-in-mountain-array/
 
 /**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(int low, int high, MountainArray &mountainArr) {
        if(low>high)
            return -1;
        int mid=(high+low)/2;
        int p=mountainArr.get(mid);
        int q=mountainArr.get(mid-1);
        int r=mountainArr.get(mid+1);
        if(p>q && p>r)
            return mid;
        if(q>p)
            return peak(low, mid,mountainArr);
        else
            return peak(mid, high,mountainArr);
    }
    int bsearch(int low, int high,int target, MountainArray &mountainArr) {
        if(high>=low){
            int mid=(high+low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target){
                return bsearch(low, mid-1,target, mountainArr);
            }
            else
                return bsearch(mid+1, high,target, mountainArr);
        }
        return -1;
    }
    int bsearch1(int low, int high,int target, MountainArray &mountainArr) {
        if(high>=low){
            int mid=(high+low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target){
                return bsearch1(mid+1, high,target, mountainArr);
            }
            else
                return bsearch1(low, mid-1,target, mountainArr);
        }
        return -1;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0, high=mountainArr.length()-1;
        int p=peak(low, high,mountainArr);
        if(mountainArr.get(p)==target)
            return p;
        int index=bsearch(low, p-1,target, mountainArr);
        if(index!=-1)
            return index;
        int index1=bsearch1(low, high,target, mountainArr);
        return index1;
    }
};
