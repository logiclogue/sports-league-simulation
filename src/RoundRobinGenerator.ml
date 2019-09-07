open RoundRobinHelpers

type t = FixtureListGenerator.t

let iterate team_list =
    split team_list
        |> equalise
        |> FunctionHelpers.uncurry zip_opt

let generate team_list =
    [iterate team_list]
