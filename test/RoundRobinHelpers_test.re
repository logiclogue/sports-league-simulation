open Mocha;
open Chai;
open RoundRobinHelpers;

describe("RoundRobinHelpers", () => {
    describe("split", () => {
        context("given an empty list", () => {
            it("returns [], []", () => {
                expect(split([]))->t->deep->equal(([], []));
            });
        });

        context("given [1]", () => {
            it("returns [1], []", () => {
                let result = split([1]);

                expect(result)->t->deep->equal(([1], []));
            });
        });

        context("given [1, 2]", () => {
            it("returns [1], [2]", () => {
                let result = split([1, 2]);

                expect(result)->t->deep->equal(([1], [2]));
            });
        });

        context("given [1, 2, 3]", () => {
            it("returns [1, 2], [3]", () => {
                let result = split([1, 2, 3]);

                expect(result)->t->deep->equal(([1, 2], [3]));
            });
        });
    });
});
