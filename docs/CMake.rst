.. _building-with-cmake:

===================================
Building OclDeepLearning with CMake
===================================

.. contents::
   :local:

Introduction
============

`CMake <http://www.cmake.org/>`_ is a cross-platform build-generator tool. CMake
does not build the project, it generates the files needed by your build tool
(GNU make, Visual Studio, etc) for building OclDeepLearning.

If you are really anxious about getting a functional OclDeepLearning build, go
to the `Quick start`_ section. If you are a CMake novice, start on
`Basic CMake usage`_ and then go back to the `Quick start`_ once you know what
you are doing. The `Options and variables`_ section is a reference for
customizing your build. If you already have experience with CMake, this is the
recommended starting point.

.. _Quick start:

Quick start
===========

We use here the command-line, non-interactive CMake interface.

#. `Download <http://www.cmake.org/cmake/resources/software.html>`_ and install
   CMake. Version 2.8 is the minimum required.

#. Open a shell. Your development tools must be reachable from this shell
   through the PATH environment variable.

#. Create a directory for containing the build. It is not supported to build
   OclDeepLearning on the source directory. cd to this directory:

   .. code-block:: bash

     $ mkdir mybuilddir
     $ cd mybuilddir

#. Execute this command on the shell replacing
   `path/to/OclDeepLearning/source/root` with
   the path to the root of your OclDeepLearning source tree:

   .. code-block:: bash

     $ cmake path/to/OclDeepLearning/source/root

   CMake will detect your development environment, perform a series of test and
   generate the files required for building OclDeepLearning. CMake will use
   default values for all build parameters. See the `Options and variables`_
   section for fine-tuning your build.

   This can fail if CMake can't detect your toolset, or if it thinks that the
   environment is not sane enough. On this case make sure that the toolset that
   you intend to use is the only one reachable from the shell and that the shell
   itself is the correct one for you development environment. CMake will refuse
   to build MinGW makefiles if you have a POSIX shell reachable through the PATH
   environment variable, for instance. You can force CMake to use a given build
   tool, see the `Usage`_ section.

.. _Basic CMake usage:
.. _Usage:

Basic CMake usage
=================

This section explains basic aspects of CMake, mostly for explaining those
options which you may need on your day-to-day usage.

CMake comes with extensive documentation in the form of html files and on the
cmake executable itself. Execute ``cmake --help`` for further help options.

CMake requires to know for which build tool it shall generate files (GNU make,
Visual Studio, Xcode, etc). If not specified on the command line, it tries to
guess it based on you environment. Once identified the build tool, CMake uses
the corresponding *Generator* for creating files for your build tool. You can
explicitly specify the generator with the command line option ``-G "Name of the
generator"``. For knowing the available generators on your platform, execute

.. code-block:: bash

  $ cmake --help

This will list the generator's names at the end of the help text. Generator's
names are case-sensitive. Example:

.. code-block:: bash

  $ cmake -G "Visual Studio 9 2008" path/to/OclDeepLearning/source/root

For a given development platform there can be more than one adequate
generator. If you use Visual Studio "NMake Makefiles" is a generator you can use
for building with NMake. By default, CMake chooses the more specific generator
supported by your development environment. If you want an alternative generator,
you must tell this to CMake with the ``-G`` option.

.. todo::

  Explain variables and cache. Move explanation here from #options section.

.. _Options and variables:

Options and variables
=====================

Variables customize how the build will be generated. Options are boolean
variables, with possible values ON/OFF. Options and variables are defined on the
CMake command line like this:

.. code-block:: bash

  $ cmake -DVARIABLE=value path/to/OclDeepLearning/source/root

You can set a variable after the initial CMake invocation for changing its
value. You can also undefine a variable:

.. code-block:: bash

  $ cmake -UVARIABLE path/to/OclDeepLearning/source/root

Variables are stored on the CMake cache. This is a file named ``CMakeCache.txt``
on the root of the build directory. Do not hand-edit it.

Variables are listed here appending its type after a colon. It is correct to
write the variable and the type on the CMake command line:

.. code-block:: bash

  $ cmake -DVARIABLE:TYPE=value path/to/OclDeepLearning/source/root

Frequently-used CMake variables
-------------------------------

Here are listed some of the CMake variables that are used often. For full
documentation, check the CMake docs or execute
``cmake --help-variable VARIABLE_NAME``.

**CMAKE_BUILD_TYPE**:STRING
  Sets the build type for ``make`` based generators. Possible values are
  Release, Debug, RelWithDebInfo and MinSizeRel. On systems like Visual Studio
  the user sets the build type with the IDE settings.

**CMAKE_INSTALL_PREFIX**:PATH
  Path where OclDeepLearning tools will be installed if "make install" is
  invoked or the "INSTALL" target is built.

Executing the test suite
========================

Testing is performed when the *check* target is built. For instance, if you are
using makefiles, execute this command while on the top level of your build
directory:

.. code-block:: bash

  $ make check

On Visual Studio, you may run tests to build the project "check".

Cross compiling
===============

See `this wiki page <http://www.vtk.org/Wiki/CMake_Cross_Compiling>`_ for
generic instructions on how to cross-compile with CMake. It goes into detailed
explanations and may seem daunting, but it is not. On the wiki page there are
several examples including toolchain files. Go directly to `this section
<http://www.vtk.org/Wiki/CMake_Cross_Compiling#Information_how_to_set_up_various_cross_compiling_toolchains>`_
for a quick solution.
