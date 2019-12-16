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
// NOTE: Resolve in src/Hello/Hello.re line: 1,3,18-24 by @ri7nz

ReactDOMRe.renderToElementWithId(
  <Hello name="world" />,
  "app"
);

