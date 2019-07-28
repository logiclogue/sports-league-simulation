open Mocha;
open Chai;
open RoundRobinGenerator;

describe("RoundRobinGenerator", () => {
    context("given no teams", () => {
        it("returns no fixtures", () => {
            expect(generate([]))->t->deep->equal([]);
        });
    });
});
