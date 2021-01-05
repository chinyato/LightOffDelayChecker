                         ChituBox LightOffDelayChecker Ver0.1.5

                         Copyright 2020-2021 White-door Inc.


このソフトウェアはオープンソースです。
ソースコードはMIT Licenseの元に公開されます。

MIT License

Copyright (c) 2020-2021 White-door Inc. (Yasushi Shirato)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.



・使用方法

起動時にはCHITUBOXの設定を読んで自動的に計算します。
ただしフォルダやファイルが見つからなかった場合には読み込まずに
起動しますので以下のように手動でファイルを選択してください。

(1) CHITUBOXのインストールバージョンをコンボボックスから選択します。
　　レジストリに登録されたインストール先を読み込めた場合には
　　コンボボックスの下のインストール先欄にインストール先フォルダが
　　表示されます。（手動でインストール先欄を書き換える事も可能です。）

(2) プロファイル読み込みボタンをクリックしてファイル選択ダイアログを
　　開き、エクスポートしたプロファイルの設定ファイルを選択して
　　開くボタンをクリックします。

(3) 計算ボタンを押します。

(4) 『消灯遅延時間　－　合計所用時間(秒)』欄に設定した消灯遅延時間と
　　ビルドプレートの上げ下げに掛かる合計時間との差が表示されます。
　　この値がマイナスになった場合には背景色が黄色で表示されます。

　　時間の差は+２～３秒の間になるように設定するようです。

(5) リフト高さ(mm)、上昇速度(mm/分)、リトラクト速度(mm/分)、消灯遅延時間(秒)の
　欄を書き換えて計算ボタンをクリックすると書き換えた設定での秒数の差を再計算
　出来ます。

　　※実際の設定はChituBoxにて書き換えてください。


・動作環境

試作版につき以下の環境のみで動作確認を行っています。

Macbook Air 2013 Mid
Window8.1 Pro (Bootcamp)
CPU i5-4250U 1.3GHz -1.9GHz
メモリ 4GB

Phrozen Sonic Mini
ChituBox 1.7.0
ChituBox 1.8.0 Beta

・開発環境

Embarcadero C++Builder 10.1 Berlin


・免責事項

このソフトウェアを使用したことによる一切の損害について作者は補償しません。
自己責任にて使用してください。

・更新履歴

Version 0.1.2

  ChituBox 1.6.4.3 Beta でリトラクト速度の項目名がnormalDropSpeedとなって
  いたので対応。1.7.0ではnormalLayerDropSpeedとなっている。

Version 0.1.3

  起動時にC:\Users\(ユーザー名)\AppData\Local\ChiTuBox 以下にある global.cfg
  及び \machine\1.cfg から読み込める場合には自動的に読み込み計算を行うように
  改良。

Version 0.1.4

　メニューやラベルの英語表示機能を追加。
　LocalAPPDataフォルダを開くボタンを追加。
　細かい部品位置の調整を行った。
　MITライセンスにてソースコードを公開。

Version 0.1.5

　ChituBox 1.8.0 Beta に対応。バージョンを変更した時にデータを初期化するように
　改良。
