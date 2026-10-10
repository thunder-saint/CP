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
bool intersect(const PT &p1, const PT &p2, const PT &p3, const PT &p4) {
    int o1 = p3.orientation(p1, p2), o2 = p4.orientation(p1, p2);
    int o3 = p1.orientation(p3, p4), o4 = p2.orientation(p3, p4);
    if (o1 != o2 && o3 != o4) return true;
    if (p3.on_segment(p1, p2) || (p4.on_segment(p1, p2)) ||
        p1.on_segment(p3, p4) || p2.on_segment(p3, p4)) return true;
    return false;
}
pair<PT, PT> closest_pair(vector<PT> v) {
    int n = v.size();
    sort(all(v));
    vector<PT> t(n);
    int min_d2 = LLONG_MAX;
    pair<PT, PT> best_pair;
    auto upd = [&](const PT &p1, const PT &p2) {
        int d = p1.dist(p2);
        if (d < min_d2) {
            min_d2 = d, best_pair = {p1, p2};
        }
    };
    auto solve = [&](auto &self, int l, int r) -> void {
        if (r - l <= 3) {
            for (int i = l; i < r; ++i) {
                for (int j = i + 1; j < r; ++j) upd(v[i], v[j]);
            }
            sort(v.begin() + l, v.begin() + r, 
                [](const PT &a, const PT &b) {return a.y < b.y;});
            return;
        }
        int mid = (l + r) / 2, mid_x = v[mid].x;
        self(self, l, mid), self(self, mid, r);
        merge(v.begin() + l, v.begin() + mid, v.begin() + mid, 
            v.begin() + r, t.begin(), [](const PT &a, const PT &b) 
             {return a.y < b.y; });
        copy(t.begin(), t.begin() + (r - l), v.begin() + l);
        int tsz = 0;
        for (int i = l; i < r; ++i) {
            int dx = v[i].x - mid_x;
            if (dx * dx < min_d2) {
                for (int j = tsz - 1; j >= 0; --j) {
                    int dy = v[i].y - t[j].y;
                    if (dy * dy >= min_d2) break;
                    upd(v[i], t[j]);
                }
                t[tsz++] = v[i];
            }
        }
    };
    solve(solve, 0, n);
    return best_pair;
}
