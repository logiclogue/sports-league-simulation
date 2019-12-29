type rating = int
type rating_change = int
type seed = string

type team_name = string
type team = team_name * rating
type team_get_rating = team -> rating
type find_team = team_name -> team

type fixture = team_name * team_name

type result = Win | Draw | Loss

type outcome = result * rating_change

type simulate_fixture = fixture -> outcome
