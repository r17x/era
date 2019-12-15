'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var Hello$ReasonReactExamples = require("./Hello/Hello.bs.js");

var container = document.createElement("div");

container.id = "app";

document.body.appendChild(container);

ReactDOMRe.renderToElementWithId(React.createElement(Hello$ReasonReactExamples.make, {
          name: "world"
        }), "app");

exports.container = container;
/* container Not a pure module */
