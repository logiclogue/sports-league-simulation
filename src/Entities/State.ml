type user_controlled = bool

type t = {
    seed: Domain.seed;
    fixed_ratings: bool;
    rating_k_factor: Domain.rating;
    teams: (Domain.team * user_controlled) list;
    results: Domain.outcome list;
}
