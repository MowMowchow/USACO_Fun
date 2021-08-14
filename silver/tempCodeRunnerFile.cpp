);
    if (r == arr.end()){
      arr.clear();
      arr.insert(b);
      vis[b] = 1;
      cout << "1 ";
    } else {
      a++;
      auto l = arr.lower_bound(a);
      if (l == arr.end()){
        arr.insert(b);
        vis[b] = arr.size();
      } else {