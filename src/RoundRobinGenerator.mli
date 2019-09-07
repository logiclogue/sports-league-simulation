type t = FixtureListGenerator.t

val generate : t
val iterate : Team.t list -> Fixture.t list
val generate_fold_f : (Fixture.t list list -> Team.t -> Fixture.t list list) -> Fixture.t list list -> Team.t list -> Fixture.t list list
