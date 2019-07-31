open BsHelpers;
open Mocha;
open Chai;
open RoundRobinGenerator;

describe("RoundRobinGenerator", () => {
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
});
