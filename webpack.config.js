const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const WasmPackPlugin = require('@wasm-tool/wasm-pack-plugin')

module.exports = {
  entry: './src/Index.bs.js',
  mode: 'development',
  output: {
    path: path.join(__dirname, 'dist'),
    filename: 'app.[hash].js'
  },
  plugins: [
    new HtmlWebpackPlugin(),
    new WasmPackPlugin({
      crateDirectory: path.resolve(__dirname, 'rust'),
      outDir: path.resolve(__dirname, 'src', 'Wasm'),
      outName: 'app'
    })
  ]
}
