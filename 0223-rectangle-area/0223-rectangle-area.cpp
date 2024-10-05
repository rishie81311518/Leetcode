class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long h1 = ay2 + 0ll - ay1, l1 = ax2 + 0ll - ax1;
        long long h2 = by2 + 0ll - by1, l2 = bx2 + 0ll - bx1;
        
		// if rectangle 2 lies between rectange 1
        if(ay2 >= by2 && ay1 <= by1 && ax2 >= bx2 && ax1 <= bx1) {
            return l1*h1;
        }
			// if rectangle 1 lies between rectange 2
        if(by2 >= ay2 && by1 <= ay1 && bx2 >= ax2 && bx1 <= ax1) {
            return l2*h2;
        }
        
		// if both rectangles do not overlap
        if(ay2 <= by1 || ay1 >= by2 || ax2 <= bx1 || ax1 >= bx2)
            return l1*h1 + l2*h2;
        
		// partial overlap
        int mx1 = max(ax1, bx1);
        int my1 = max(ay1, by1);
        int mx2 = min(ax2, bx2);
        int my2 = min(ay2, by2);
        
        int ml = mx2-mx1;
        int mh = my2-my1;
        
        return l1*h1 + 0ll + l2*h2  + 0ll - ml*mh;
        
    }
};