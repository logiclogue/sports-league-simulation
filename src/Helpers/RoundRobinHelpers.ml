(*let split xs =
    match xs with
    | [] -> [], []
    | [x] -> [x], []
    | [x; y] -> [x], [y]
    | [x; y; z] -> [x; y], [z]
    | [x; y; z; w] -> [x; y], [z; w]*)

let rec take n xs =
    if n <= 0 then
        []
    else
        match xs with
        | x :: xs -> x :: (take (n - 1) xs)
        | []      -> []

let rec drop n xs =
    if n <= 0 then
        xs
    else
        match xs with
        | x :: xs -> drop (n - 1) xs
        | []      -> []

let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    take half xs, drop half xs

let equalise xys =
    [], []

let zip_opt x_opts y_opts =
    []

let rotate xs =
    []
