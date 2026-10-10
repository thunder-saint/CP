struct Polygon {
    vector<PT> p;
    int n;
    Polygon(const vector<PT> &v) : p(v), n(v.size()){}
    int location(const PT &pt) {
        int cnt = 0;
        PT I = {pt.x + 3000000000LL, pt.y + 1LL};
        for(int i = 0; i < n; i++) {
            if(pt.on_segment(p[i], p[(i + 1) % n])) return 0;
            if(intersect(p[i], p[(i + 1) % n], pt, I)) cnt++;
        } 
        if(cnt % 2) return 1;
        else return -1;
    }
    int area2() const {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += p[i].cross(p[(i + 1) % n]);
        }
        return abs(ans);
    }
    double area() const {
        return area2() / 2.0;
    }
    int boundary_point() const {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            PT p1 = p[i], p2 = p[(i + 1) % n];
            int dx = abs(p1.x - p2.x), dy = abs(p1.y - p2.y);
            cnt += std::gcd(dx, dy);
        }
    return cnt;
    }
    int interior_points() const {
        return (area2() - boundary_point() + 2) / 2;
    }
};
