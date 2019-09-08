type t = FixtureListGenerator.t

val generate : t
val iterate : Team.t option list -> Fixture.t list
(*val generate_fold_f : (Fixture.t list list -> Team.t list -> Fixture.t list list) -> Fixture.t list list -> Team.t list -> Fixture.t list list
val triangle_number : int -> int
val number_of_matches : int -> int*)
