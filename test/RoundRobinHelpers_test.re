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
        context("given []", () => {
            it("returns []", () => {
                let result = equalise([]);

                expect(result)->t->deep->equal([]);
            });
        });

        context("given [1]", () => {
            it("returns [Some 1, None]", () => {
                let result = equalise([1]);

                expect(result)->t->deep->equal([Some(1), None]);
            });
        });

        context("given [1, 2]", () => {
            it("returns [Some 1, Some 2]", () => {
                let result = equalise([1, 2]);

                expect(result)->t->deep->equal([Some(1), Some(2)]);
            });
        });
    });

    describe("zip_opt", () => {
        context("given [Some 1, None] and [Some 2, Some 42]", () => {
            let input_left = [Some(1), None];
            let input_right = [Some(2), Some(42)];

            it("returns [(1, 2)]", () => {
                let result = zip_opt(input_left, input_right);

                expect(result)->t->deep->equal([(1, 2)]);
            });
        });
    });

    describe("rotate", () => {
        context("given []", () => {
            let result = rotate([]);

            it("returns []", () => {
                expect(result)->t->deep->equal([]);
            });
        });

        context("given [1]", () => {
            let result = rotate([1]);

            it("returns [1]", () => {
                expect(result)->t->deep->equal([1]);
            });
        });

        context("given [1, 2]", () => {
            let result = rotate([1, 2]);

            it("returns [1, 2]", () => {
                expect(result)->t->deep->equal([1, 2]);
            });
        });

        context("given [1, 2, 3]", () => {
            let result = rotate([1, 2, 3]);

            it("returns [1, 3, 2]", () => {
                expect(result)->t->deep->equal([1, 3, 2]);
            });
        });
    });
});
