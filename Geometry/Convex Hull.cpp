void convex_hull(vector<PT> &a, bool cl = false) {
    if (a.size() <= 1) return;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    PT p1 = a[0], p2 = a.back();
    vector<PT> up, dw;
    up.push_back(p1), dw.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || p1.cw(a[i], p2, cl)) { 
            while (up.size() >= 2 && !up[up.size()-2].cw(up[up.size()-1], a[i], cl))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || p1.ccw(a[i], p2, cl)) { 
            while(dw.size() >= 2 && !dw[dw.size()-2].ccw(dw[dw.size()-1], a[i], cl))
                dw.pop_back();
            dw.push_back(a[i]);
        }
    }
    if (cl && up.size() == a.size()) {
        reverse(all(a)); return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++) a.push_back(up[i]);
    for (int i = dw.size() - 2; i > 0; i--) a.push_back(dw[i]);
}
