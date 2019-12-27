type rating = int

type rating_change = int

type team_name = string

type team = team_name * rating

type fixture = team * team

type get_rating = team -> rating

type result = Win | Draw | Loss

type outcome = result * rating_change

type get_result = teams -> fixture -> result
