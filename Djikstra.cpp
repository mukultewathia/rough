vector<long long >  dijkstra(int source, int sz)
{

	vector<int> pi(sz + 1, -1);
	dist.resize(sz + 1);
	dist.assign(sz + 1, 1e15);

	auto cmp = [](int i, int j)
	{
		if (dist[i] != dist[j])
			return dist[i] < dist[j];
		return i < j;
	};

	// added comments
	// Hello mafia;
	set< int, decltype(cmp) >  st(cmp);
	dist[ source ] = 0;
	for (int i = 1; i <= sz; i++ ) st.insert(i);
	while ( !st.empty() )
	{
		int x = *st.begin();
		st.erase(st.begin());
		for ( auto i : adj[x] )
		{
			if ( dist[ i.ff ] > dist[ x ] + i.ss )
			{
				st.erase(i.ff);
				dist[ i.ff ] = dist[x] + i.ss;
				pi[ i.ff ] = x;
				st.insert(i.ff);
			}
		}
	}

	return dist;

}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //
int n;
vector < vector < pii > > adj(10);

void dijkstra(int s)
{
	int vis[n];
	int dis[n];

	memset(vis, 0, sizeof(vis));
	loop(i, 0, n)dis[i] = inf;

	dis[s] = 0;
	priority_queue < pii, vpii , greater<pii> > q;

	q.push({0, s});

	while ( !q.empty() )
	{
		int v = q.top().ss;
		q.pop();

		if ( dis[v] == inf ) break;

		for (int j = 0 ; j < adj[v].size(); j++)
		{
			int dest = adj[v][j].ff;
			int len =  adj[v][j].ss;

			if ( dis[dest] > dis[v] + len)
			{
				dis[dest] = dis[v] + len;
				q.push({ dis[dest], dest });
			}
		}
	}

	cout << s << endl;

	loop(i, 0, n) cout << i << " ::! " <<  dis[i]  << endl;



}
void solve()
{
	cin >> n;
	int k ; cin >> k;
	adj.clear();

	loop(i, 0, k)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].pb({v, d});
		adj[v].pb({u, d});
	}
	int s; cin >> s;
	dijkstra(s);
}

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;

	while (t--) solve();

}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //













