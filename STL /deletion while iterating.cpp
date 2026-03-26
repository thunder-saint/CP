// x can be set, map, multiset, multimap
for (auto it = x.begin(); it != x.end();) {
    if (/*condition*/) it = x.erase(it);
    else ++it;
}
