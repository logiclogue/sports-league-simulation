let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    ListHelpers.take half xs, ListHelpers.drop half xs

let equalise (xs, ys) =
    let f = OptionHelpers.map (fun x -> x) in

    ListHelpers.complete_zip f (xs, ys)
        |> ListHelpers.unzip

let zip_opt x_opts y_opts =
    []

let rotate xs =
    []
