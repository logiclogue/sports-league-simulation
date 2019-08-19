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

    describe("equalise", () => {
        context("given [], []", () => {
            it("returns [], []", () => {
                let result = equalise(([], []));

                expect(result)->t->deep->equal(([], []));
            });
        });

        context("given [1], [1]", () => {
            it("returns [Some 1], [Some 1]", () => {
                let result = equalise(([1], [1]));

                expect(result)->t->deep->equal(([Some(1)], [Some(1)]));
            });
        });

        context("given [1, 2], [1]", () => {
            it("returns [Some 1, Some 2], [Some 1, None]", () => {
                let result = equalise(([1, 2], [1]));

                let expected_left = [Some(1), Some(2)];
                let expected_right = [Some(1), None];

                expect(result)->t->deep->equal((expected_left, expected_right));
            });
        });
    });
});
