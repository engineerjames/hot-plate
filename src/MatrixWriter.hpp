#ifndef HOTPLATE_MATRIX_WRITER_HPP
#define HOTPLATE_MATRIX_WRITER_HPP

#include <fstream>
#include <string>

template < typename MatrixType >
class MatrixWriter
{
   public:
    MatrixWriter( const MatrixType& matrix )
        : matrix_( matrix )
    {
    }

    void write( const std::string& fileName ) const
    {
        std::fstream file_ { fileName, std::fstream::out };

        if ( file_.is_open() )
        {
            // write the file
            for ( MatrixType::size_type i = 0; i < matrix_.size(); ++i )
            {
                for ( MatrixType::size_type j = 0; j < matrix_[i].size(); ++j )
                {
                    if ( j != matrix_[i].size() - 1 )
                    {
                        file_ << matrix_[i][j] << ',';
                    }
                    else
                    {
                        file_ << matrix[i][j] << '\n';
                    }
                }
            }
        }

        file_.close();
    }

   private:
    const MatrixType& matrix_;
};

#endif