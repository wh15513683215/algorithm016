学习笔记
双向BFS

void bibfs(Node* start, Node* end) {
    set<Node*> front {start};
    set<Node*> back {end};
    set<int> visited;
    while (!front.empty()) {
        set<Node*> newset;
        for (const auto& node : front) {
            for (const auto& val : generate_new_nodes(node->val)) {
                if (visited.find(val) != visited.end()) {
                    newset.insert(val);
                }
            }
        }
        front = newset;
        if (front.size() > back.size()) {
            swap(front, back);
        }
    }
    return 0;
}
温馨提示：本周学习的视频笔记在脑图中
https://shimo.im/docs/vYvx8tQcP9V6gDWt/ 《C++模板》，可复制链接后用石墨文档 App 或小程序打开
https://shimo.im/docs/VpjCyHVP9drDHhHd/ 「My Code」，可复制链接后用石墨文档 App 或小程序打开