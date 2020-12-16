# LightOffDelayChecker
calculate ChiTuBox Light Off Delay tool.

                         ChituBox LightOffDelayChecker Ver0.1.4

                         Copyright 2020 White-door Inc.


このソフトウェアはオープンソースです。
ソースコードはMIT Licenseの元に公開されます。

・使用方法

起動時にはCHITUBOXの設定を読んで自動的に計算します。
ただしフォルダやファイルが見つからなかった場合には
読み込まずに起動しますので以下のように手動でファイル
を選択してください。

(1) CHITUBOXのインストールバージョンをコンボ
　　ボックスから選択します。
　　レジストリに登録されたインストール先を読み込めた
  　場合にはコンボボックスの下のインストール先欄に
   インストール先フォルダが表示されます。
  （手動でインストール先欄を書き換える事も可能です。）

(2) プロファイル読み込みボタンをクリックしてファイル
　　選択ダイアログを開き、エクスポートしたプロファイルの
 　設定ファイルを選択して開くボタンをクリックします。

(3) 計算ボタンを押します。

(4) 『消灯遅延時間　－　合計所用時間(秒)』欄に設定した
　　消灯遅延時間とビルドプレートの上げ下げに掛かる合計
  　時間との差が表示されます。
　　この値がマイナスになった場合には背景色が黄色で
  　表示されます。

　　時間の差は+２～３秒の間になるように設定するようです。

(5) リフト高さ(mm)、上昇速度(mm/分)、リトラクト速度
　　(mm/分)、消灯遅延時間(秒)の欄を書き換えて計算ボタンを
  　クリックすると書き換えた設定での秒数の差を再計算出来ます。

　　※実際の設定はChituBoxにて書き換えてください。


・動作環境

試作版につき以下の環境のみで動作確認を行っています。

Macbook Air 2013 Mid
Window8.1 Pro (Bootcamp)
CPU i5-4250U 1.3GHz -1.9GHz
メモリ 4GB

Phrozen Sonic Mini
ChituBox 1.7.0

・開発環境

Embarcadero C++Builder 10.1 Berlin


・免責事項

このソフトウェアを使用したことによる一切の損害について
作者は補償しません。自己責任にて使用してください。

・更新履歴

Version 0.1.2

  ChituBox 1.6.4.3 Beta でリトラクト速度の項目名が
  normalDropSpeedとなっていたので対応。1.7.0では
  normalLayerDropSpeedとなっている。

Version 0.1.3

  起動時にC:\Users\(ユーザー名)\AppData\Local\ChiTuBox 以下に
  ある global.cfg 及び \machine\1.cfg から
  読み込める場合には自動的に読み込み計算を行うように改良。

Version 0.1.4

　メニューやラベルの英語表示機能を追加。
　LocalAPPDataフォルダを開くボタンを追加。
　細かい部品位置の調整を行った。
　MITライセンスにてソースコードを公開。



MIT License

Copyright (c) 2020 White-door Inc. (Yasushi Shirato)

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

 
MIT ライセンス（日本語訳）

Copyright (c) 2020 株式会社ホワイトドア & Yasushi Shirato

以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）
の複製を取得するすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。
これには、ソフトウェアの複製を使用、複写、変更、結合、掲載、頒布、サブライセンス、
および/または販売する権利、およびソフトウェアを提供する相手に同じことを許可する権利も
無制限に含まれます。

上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に
記載するものとします。

ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく
提供されます。ここでいう保証とは、商品性、特定の目的への適合性、および権利非侵害に
ついての保証も含みますが、それに限定されるものではありません。 作者または著作権者は、
契約行為、不法行為、またはそれ以外であろうと、ソフトウェアに起因または関連し、あるいは
ソフトウェアの使用またはその他の扱いによって生じる一切の請求、損害、その他の義務について
何らの責任も負わないものとします。 

 

