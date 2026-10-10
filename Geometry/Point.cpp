struct PT {
    int x, y;
    PT operator + (const PT &a) const {return {x + a.x, y + a.y};}
    PT operator - (const PT &a) const {return {x - a.x, y - a.y};}
    bool operator == (const PT &a) const {return (x==a.x)&&(y==a.y);}
    bool operator <(const PT &a)const{return tie(x, y)<tie(a.x, a.y);}
    int dot (const PT &a) const { return x * a.x + y * a.y; }
    int cross (const PT &a) const {return x * a.y - y * a.x;}
    int orientation (const PT &a, const PT &b) const {
        int val = (a - b).cross(*this - b);
        return (val > 0) - (val < 0);
    }
    bool on_segment (const PT &a, const PT &b) const {
        return orientation(a, b) == 0 && x <= max(a.x, b.x) 
        && x >= min(a.x, b.x) && y <= max(a.y, b.y) && y >= min(a.y, b.y);
    }
    bool cw (const PT &a, const PT &b, bool collinear = false) const {
        int val = (a - *this).cross(b - *this) ;
        return val < 0 || (collinear && val == 0);
    }
    bool ccw (const PT &a, const PT &b, bool collinear = false) const {
        int val = (a - *this).cross(b - *this); 
        return val > 0 || (collinear && val == 0);
    }
    int dist(const PT &a) const {return ((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));}//
    double perpendicular_dist (const PT &a, const PT &b) const {
        double A = (a.y - b.y), B = -(a.x - b.x), C = -(A * a.x + B * a.y);
        double up = abs(A * x + B * y + C), down = sqrt(A * A + B * B);
        return up / down;
    }
};
