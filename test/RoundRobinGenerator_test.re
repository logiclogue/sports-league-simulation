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
});
