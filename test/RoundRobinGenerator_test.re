open Mocha;
open Chai;
open RoundRobinGenerator;

describe("RoundRobinGenerator", () => {
    describe("generate", () => {
        context("given no teams", () => {
            it("returns no fixtures", () => {
                expect(generate([]))->t->deep->equal([]);
            });
        });

        context("given 1 team", () => {
            it("returns no fixtures", () => {
                let teams = [Stubs.derby];

                expect(generate(teams))->t->deep->equal([]);
            });
        });

        context("given 2 teams", () => {
            it("returns 1 fixture", () => {
                let teams = [Stubs.derby, Stubs.forest];

                let fixture = (Stubs.derby, Stubs.forest);

                expect(generate(teams))->t->deep->equal([[fixture]]);
            });
        });
    });

    describe("iterate", () => {
        context("given 2 teams", () => {
            let teams = [Some(Stubs.derby), Some(Stubs.forest)];
            let fixtures = [(Stubs.derby, Stubs.forest)];

            let result = iterate(teams);

            it("returns 1 fixture", () => {
                expect(result)->t->deep->equal(fixtures);
            });
        });

        context("given 3 teams", () => {
            let teams = [
                Some(Stubs.derby),
                Some(Stubs.forest),
                Some(Stubs.leicester),
                None
            ];

            context("no rotations", () => {
                let fixtures = [(Stubs.derby, Stubs.leicester)];

                let result = iterate(teams);

                it("returns derby vs leicester", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });

            context("1 rotation", () => {
                let teams = RoundRobinHelpers.rotate(teams);

                let fixtures = [(Stubs.leicester, Stubs.forest)];

                let result = iterate(teams);

                it("returns leicester vs forest", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });

            context("2 rotation", () => {
                let teams = FunctionHelpers.reapply(
                    RoundRobinHelpers.rotate,
                    2,
                    teams
                );

                let fixtures = [(Stubs.derby, Stubs.forest)];

                let result = iterate(teams);

                it("returns derby vs forest", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });
        });

        context("given 4 teams", () => {
            let teams = [
                Some(Stubs.derby),
                Some(Stubs.forest),
                Some(Stubs.leicester),
                Some(Stubs.man_united)
            ];

            context("no rotations", () => {
                let fixtures = [
                    (Stubs.forest, Stubs.man_united),
                    (Stubs.derby, Stubs.leicester)
                ];

                let result = iterate(teams);

                it("returns expected 2 fixtures", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });

            context("1 rotation", () => {
                let teams = RoundRobinHelpers.rotate(teams);

                let fixtures = [
                    (Stubs.leicester, Stubs.forest),
                    (Stubs.derby, Stubs.man_united)
                ];

                let result = iterate(teams);

                it("returns expected 2 fixtures", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });

            context("2 rotations", () => {
                let teams = FunctionHelpers.reapply(
                    RoundRobinHelpers.rotate,
                    2,
                    teams
                );

                let fixtures = [
                    (Stubs.man_united, Stubs.leicester),
                    (Stubs.derby, Stubs.forest)
                ];

                let result = iterate(teams);

                it("returns expected 2 fixtures", () => {
                    expect(result)->t->deep->equal(fixtures);
                });
            });
        });
    });
});
