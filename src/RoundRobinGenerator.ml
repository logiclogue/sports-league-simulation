open RoundRobinHelpers

type t = FixtureListGenerator.t

let iterate team_list =
    split team_list
        |> FunctionHelpers.uncurry zip_opt

(*let generate_fold_f rounds teams rounds =
    

let triangle_number n =
    (n * (n + 1)) / 2

let number_of_matches teams_count =
    triangle_number (teams_count - 1)*)

let generate team_list =
    []
