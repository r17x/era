[@bs.val] external document: Js.t({..}) = "document";

let container = document##createElement("div");

container##id #= "app";

document##body##appendChild(container);

// TODO: This is not works :(
//
// module type WasmType = {
//  let paint: unit => unit;
// };

// module type WasmType = (module type of WebAssembly);
// DynamicImport.(
//  import("./Wasm/app.js")
// |> resolve
//  |> Js.Promise.then_(((module Wasm): (module WasmType)) =>
//    Wasm.paint |> Js.Promise.resolve 
//  )
// );

ReactDOMRe.renderToElementWithId(
  <Hello name="world" />,
  "app"
);

