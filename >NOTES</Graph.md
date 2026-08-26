# Topological sorting #
- the number of valid topological orderings: n! / (∏ sz(i)) i = 1,..., n
---
# MST #
- a node belongs to 
  - "None": Endpoints have the same DSU root (creates a cycle with *cheaper* edges).
  - "At least one": Connects different roots, but forms a **cycle** with *equal-weight* edges.
  - "Any" (All):** Connects different roots and is a **bridge** (mandatory connection).
