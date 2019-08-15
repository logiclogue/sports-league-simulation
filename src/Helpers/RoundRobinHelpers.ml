(*let split xs =
    match xs with
    | [] -> [], []
    | [x] -> [x], []
    | [x; y] -> [x], [y]
    | [x; y; z] -> [x; y], [z]
    | [x; y; z; w] -> [x; y], [z; w]*)

let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    let () = Js.log (List.take half xs) in

    [], []

let equalise xys =
    [], []

let zip_opt x_opts y_opts =
    []

let rotate xs =
    []
